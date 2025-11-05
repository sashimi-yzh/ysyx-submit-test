from collections import defaultdict

class BTBEntry:
    def __init__(self, pc, npc, cnt):
        self.pc = pc 
        self.npc = npc 
        self.cnt = cnt 
    def __str__(self):
        return f"BTBEntry: " + "{" + f"PC: {self.pc}, NPC: {self.npc}, Counter: {self.cnt}" + "}"
    def __repr__(self):
        return self.__str__()

class BPU:
    def __init__(self, address_size=4, prediction_method='saturating', bits=2, table_size=2):
        self.address_size = address_size
        self.prediction_method = prediction_method
        self.BTB = [BTBEntry(0, 0, 2**bits // 2) for _ in range(table_size)]
        self.tag_index = 0
        self.table_size = table_size
        self.cnt_bits = bits

    def _index_saturating(self, address):
        for i in range(len(self.BTB)):
            if self.BTB[i].pc == address:
                self.tag_index = i
                return self.tag_index
        else:
            tmp = self.tag_index
            self.tag_index+=1 
            self.tag_index %= self.table_size
            return tmp

    
    def predict(self, address, inst):
        """
        根据预测方法对给定地址的分支进行预测。
        返回值: 0=不采取, 1=采取
        """
        if self.prediction_method == 'always_taken':
            return 1
        elif self.prediction_method == 'static':
            # val immB = Cat(io.inst(31), io.inst(7), io.inst(30, 25), io.inst(11, 8), 0.U(1.W)).asSInt

            # 静态预测策略：后向分支（imm < 0）预测 Taken
            return 1 if (inst >> 31 & 0x1) else 0
        elif self.prediction_method == 'saturating':
            idx = self._index_saturating(address)
            # print(f"pred: {idx=}")
            counter = self.BTB[idx].cnt
            return 1 if counter >= (2**self.cnt_bits)//2 else 0
        else:
            raise ValueError("Unsupported prediction method.")

    def update(self, address, taken, correct):
        """
        根据分支的实际结果更新历史表。
        """
        if self.prediction_method == 'saturating':
            idx = self._index_saturating(address)
            # print(f"{idx=}")
            self.BTB[idx].pc = address
            counter = self.BTB[idx].cnt
            if taken:
                self.BTB[idx].cnt = min(counter + 1, 2**self.cnt_bits - 1)
            else:
                self.BTB[idx].cnt = max(counter - 1, 0)
        elif self.prediction_method == 'static':
            pass 
        elif self.prediction_method == 'always_taken':
            pass
        else:
            raise ValueError("Unsupported prediction method.")
        # print(self.BTB)
