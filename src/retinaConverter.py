x = []
z = ""
try:
	while True:
		z += input()
except EOFError:
	x = z.split(";")
	
stripMax = 255  # WS2812B
#stripMax = 127  # LPD8806

mul = float(stripMax) / float(63)

r = "const byte _r[128] = {"
g = "const byte _g[128] = {"
b = "const byte _b[128] = {"

for _ in range(128):
	a = x[_].split()
	r += str(round(float(a[1]) * mul)) + (", " if _ < 127 else "};\n")
	g += str(round(float(a[2]) * mul)) + (", " if _ < 127 else "};\n")
	b += str(round(float(a[3]) * mul)) + (", " if _ < 127 else "};")

print(r + g + b)
