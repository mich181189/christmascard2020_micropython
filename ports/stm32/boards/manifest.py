include("$(MPY_DIR)/extmod/uasyncio/manifest.py")
freeze("$(MPY_DIR)/drivers/dht", "dht.py")
freeze("$(MPY_DIR)/drivers/lm75", "lm75.py")
freeze("$(MPY_DIR)/drivers/display", ("lcd160cr.py", "lcd160cr_test.py"))
freeze("$(MPY_DIR)/drivers/onewire", "onewire.py")
