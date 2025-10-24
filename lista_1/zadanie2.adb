with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics; use Ada.Numerics;

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;
	
procedure Zadanie2 is
	A, B, C: Float;

	procedure Solve(A1, B1, C1: Float) is
		D: Float;
	begin
		D := B*B - 4.0*A*C;

		if D < 0.0 then
			Put_Line("Rozwiazania rownania nie naleza do zbioru liczb rzeczywistych");
		elsif D = 0.0 then
			Put_Line(Float'Image ((-B)/(2.0*A)));
		else
			Put_Line(Float'Image ((-B-Sqrt(D))/(2.0*A)) & ", ");
			Put_Line(Float'Image ((-B+Sqrt(D))/(2.0*A)));
		end if;
	end Solve;
		
begin
	Put("Enter A: ");
	Get(A);
	Put("Enter B: ");
	Get(B);
	Put("Enter C: ");
	Get(C);

	Solve(A, B, C);
end Zadanie2;