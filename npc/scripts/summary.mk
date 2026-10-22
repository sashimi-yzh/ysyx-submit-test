
FILELIST = $(WORK_DIR)/sum/sum_filelist.txt
OUTPUT_FILE = $(WORK_DIR)/build/ysyx_25020042_total.v
FIXED_FILE = $(WORK_DIR)/build/ysyx_25020042.v
PYTHON_SUM_SCRIPT := $(WORK_DIR)/tools/merge_files.py
PYTHON_FIX_SCRIPT := $(WORK_DIR)/tools/clean_verilator.py

sum: $(FIXED_FILE)
	$(VERILATOR) --lint-only -Wall -Wno-DECLFILENAME -Wno-TIMESCALEMOD $(FIXED_FILE)

$(OUTPUT_FILE): $(FILELIST)
	@python3 $(PYTHON_SUM_SCRIPT) $(FILELIST) $(OUTPUT_FILE)

$(FIXED_FILE): $(OUTPUT_FILE)
	@python3 $(PYTHON_FIX_SCRIPT) $(OUTPUT_FILE) $(FIXED_FILE)


cleansum:
	-rm  $(OUTPUT_FILE) $(FIXED_FILE)