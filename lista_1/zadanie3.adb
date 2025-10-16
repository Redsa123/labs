with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Zadanie3 is
	X, N: Integer;

	function Is_Palindrome(X,N: Integer) return Boolean is
		M: Integer := 0;
		T: Integer := X;
	begin
		while T > 0 loop
			M := N * M + (T mod N);
			T := T / N;
		end loop;
		return M = X;
	end Is_Palindrome;

begin
	Put("Enter number: ");
	Get(X);
	Put("Enter system: ");
	Get(N);

	if Is_Palindrome(X,N) then
		Put_Line("True");
	else
		Put_Line("False");
	end if;

end Zadanie3;