def main():
	def is_palindrome(x, n):
		m = 0
		t = x
		while t > 0:
			m = n * m + (t%n)
			t = t // n
		return m==x
	print(is_palindrome(3, 2))


if __name__ == "__main__":
	main()