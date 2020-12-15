
class LM75:

	def __init__(self, i2c, address=72):
		self.i2c = i2c
		self.address = address

	def get_temperature(self):
		data = self.i2c.readfrom_mem(self.address, 0, 2)
		temperature = data[0] + (data[1]/256)
		return temperature

	def shutdown(self):
		self.i2c.writeto_mem(self.address, 1, b'\x01')

	def wakeup(self):
		self.i2c.writeto_mem(self.address, 1, b'0x00')

	def is_shutdown(self):
		data = self.i2c.readfrom_mem(self.address, 1, 1)
		return (data[0] & 0x01) == 0x01
