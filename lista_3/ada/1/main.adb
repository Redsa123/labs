with Ada.Text_IO; use Ada.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;
with PrimeNumbers; use PrimeNumbers;

procedure Main is
    procedure Free is
        new Standard.Ada.Unchecked_Deallocation(Sieve, Sieve_Ptr);

        n: Natural;
        Count: Natural := 0;
        s: Sieve_Ptr;
    begin
        if Argument_Count /= 1 then
            Put_Line ("Wrong number of arguments");
            return;
        end if;

		if Integer'Value(Argument(1)) < 2 then
			Put_Line("Wrong input, n has to be greater then 1");
			return;
		end if;

        n := Natural'Value(Argument(1));
        s := new Sieve (2 .. n);

        Compute_Sieve(s);
        Count := Count_Primes(s);

        Free (s);

        Put_Line(Count'Image);
end Main;