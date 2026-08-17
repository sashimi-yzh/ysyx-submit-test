LIBCAPSTONE = tools/capstone/repo/libcapstone.so.6
SO_PATH_CAPSTONE = $(NPC_HOME)/npc_old/$(LIBCAPSTONE)
V_CXXFLAGS += -CFLAGS "-I$(NPC_HOME)/tools/capstone/repo/include -DSO_PATH_CAPSTONE=$(SO_PATH_CAPSTONE)"

$(LIBCAPSTONE):
	$(MAKE) -C $(NPC_HOME)/npc_old/tools/capstone