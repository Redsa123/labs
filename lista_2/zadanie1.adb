with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Zadanie1 is

	A, B, Res: Integer;

	function Euklides (A,B: Integer) return Integer is
		Temp: Integer;

	begin

		if A = 0 then
			return B;
		elsif B = 0 then
			return A;
		end if;

		while B /= 0 loop
			Modulo := B;
			B := A mod B;
			A := Temp;
		end loop;

		return A;
	end Euklides;

begin

	Put("Enter first integer value: ");
	Get(A);

	Put("Enter second integer value: ");
	Get(B);

	Res := Euklides(A, B);

	Put_Line("NWD: " & Integer'Image (Res));
end Zadanie1;