BIN  = $(BIN_DIR)/test
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
CFLAGS = $(INC_SRCH_PATH) $(LIB_SRCH_PATH)

$(BIN): $(SRCS)
	@echo $(CFLAGS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $^ $(CFLAGS) -Wl,-Map=$(BIN).map $(LIBS) -o $@
	@echo "    Generate Program $(notdir $(BIN)) from $^"

run:
	$(BIN) $(ARGS)

valgrind:
	@mkdir -p $(BUILD_DIR)
	valgrind --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        --verbose \
        --log-file=$(BUILD_DIR)/valgrind-out.txt \
        $(BIN) $(ARGS)

.PHONY: clean
clean:
	@$(RM) -f $(OBJS) $(BIN)
	@$(RM) -f *.expand
	@$(RM) -rf $(BIN_DIR)
	@echo "    Remove Objects:   $(OBJS)"
	@echo "    Remove Libraries:  $(notdir $(BIN))"
