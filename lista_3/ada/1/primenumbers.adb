with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

package body PrimeNumbers is
	procedure Compute_Sieve (s : Sieve_Ptr) is
		j      : Natural;
		Sqrt_N : Natural := Natural (Sqrt (Float (s'Last)));
	begin
		s.all := (others => True);

		for i in 4 .. s'Last loop
			if i mod 2 = 0 then
				s (i) := False;
			end if;
		end loop;

		for i in 3 .. Sqrt_N loop
			if s (i) then
				j := i * i;
				while j <= s'Last loop
					s (j) := False;
					j := j + 2 * i;
				end loop;
			end if;
		end loop;
	end Compute_Sieve;

	function Count_Primes (s : Sieve_Ptr) return Natural is
		Count : Natural := 1;
		I: Integer := 3;
	begin
		while I <= s'Last loop
			if s (i) then
				Count := Count + 1;
			end if;
			I := I + 2;
		end loop;
		return Count;
	end Count_Primes;
end PrimeNumbers;
