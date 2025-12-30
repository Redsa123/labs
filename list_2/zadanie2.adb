with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics; use Ada.Numerics;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

procedure Zadanie2 is
	N: Integer;

	function IsPrime(Num: Integer) return Boolean is
		Root, I: Integer;
	begin
		if Num <= 1 then
			return False;
		end if;
		if Num = 2 then
			return True;
		end if;
		if Num mod 2 = 0 then
			return False;
		end if;
		
		I := 3;
		Root := Integer(Sqrt(Float(Num)));
		while I <= Root loop
			if Num mod I = 0 then
				return False;
			end if;
			I := I+2;
		end loop;
		return True;

	end IsPrime;

begin
		Put ("Enter number: ");
		Get (N);
		if IsPrime (N) then
			Put("True");
		else
			Put("False");
		end if;

end Zadanie2;