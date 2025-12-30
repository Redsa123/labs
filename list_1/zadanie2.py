import math

def main():
	def solve(a, b, c):
		delta = b*b - 4 * a * c
		if delta < 0:
			print("Rozwiazania rownania nie naleza do zbioru liczb rzeczywistych\n")
		elif delta == 0:
			print((-1*b) / (2*a))
		else:
			print((-1*b-math.sqrt(delta))/(2*a),(-1*b+math.sqrt(delta))/(2*a))
	
	a = int(input("Enter value a: "))
	b = int(input("Enter value b: "))
	c = int(input("Enter value c: "))

	solve(a, b, c)


if __name__ == "__main__":
	main()