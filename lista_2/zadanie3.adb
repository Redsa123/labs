with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics; use Ada.Numerics;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

procedure Zadanie3 is
	N: Integer;

	procedure Dividers(Num: Integer) is
		N: Integer := Num;
		Mult2: Integer;
		Mult: Integer;
		Root: Integer;
		I: Integer := 3;

		begin

		if (N mod 2 = 0) then
			Mult2 := 0;
			while (N mod 2 = 0) loop
				Mult2 := Mult2 + 1;
				N := N/2;
			end loop;
			Put ("2^" & Integer'Image(Mult2));
			if (N > 1) then
				Put("*");
			end if;
		end if;

		Root := Integer(Sqrt(Float(N)));
		while (I <= Root) loop
			if(N mod I = 0) then
				Mult := 0;
				while (N mod I = 0) loop
					Mult := Mult + 1;
					N := N / I;
				end loop;
				Put(Integer'Image(I) & "^" & Integer'Image(Mult));
				if (N > 1) then
					Put("*");
				end if;
			end if;
			I := I+2;
		end loop;

		if N > 1 then
			Put(Integer'Image(N) & "^1");
		end if;

		end Dividers;


begin

	Put ("Enter number: ");
	Get(N);
	Dividers(N);

end Zadanie3;