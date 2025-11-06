运行指南:
1. 如果只是想测试单个缓存参数或者缓存策略,可以执行make run SETS=? WAYS=? BLOCK_SIZE=? POLICY=?  (运行时将问号替换为你的参数,最后一个POLICY只支持fifo和lru两个参数)
2. 若想测试多组参数,首先将测试的参数写入到params.txt中(目前不支持block_size的写入),接着执行make run-combinations,然后执行make analyze-result分析结果,最后分析的结果存储在summary.csv中