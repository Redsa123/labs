with Ada.Text_IO;                       use Ada.Text_IO;
with Ada.Integer_Text_IO;               use Ada.Integer_Text_IO;
with Ada.Unchecked_Deallocation;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

--Private functions

package body Primes is

   function PrimeNumbers (n : Positive) return Natural is

      type Sieve is array (Positive range <>) of Boolean;
      type Sieve_Ptr is access Sieve;

      procedure Free is new
        Standard.Ada.Unchecked_Deallocation (Sieve, Sieve_Ptr);

      Count : Natural := 0;
      s     : Sieve_Ptr;

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
         Count : Natural := 1; -- Assume 2 is prime
         I     : Integer := 3;
      begin
         while I <= s'Last loop
            if s (i) then
               Count := Count + 1;
            end if;
            I := I + 2;
         end loop;
         return Count;
      end Count_Primes;

   begin

      s := new Sieve (2 .. n);

      Compute_Sieve (s);
      Count := Count_Primes (s);

      Free (s);
      return Count;

   end PrimeNumbers;

   function Prime (n : Positive) return Positive is

      type Primes_Array is array (Integer range <>) of Positive;

      type Primes_Array_Access is access Primes_Array;

      procedure Free is new
        Ada.Unchecked_Deallocation (Primes_Array, Primes_Array_Access);

      function Nth_Prime (N : Integer) return Positive is
         Primes         : Primes_Array_Access;
         I              : Positive;
         J, Count, Flag : Integer;
      begin

         if N <= 0 then
            Put_Line ("Wrong arguments, n has to be greater than 0");
            return 1;
         end if;

         if N = 1 then
            return 2;
         end if;

         Primes := new Primes_Array (1 .. N);

         Count := 1;
         Primes (1) := 2;

         I := 3;
         Flag := 1;

         while True loop
            Flag := 1;
            J := 0;

            for J in 1 .. Count loop
               if I mod Primes (J) = 0 then
                  Flag := 0;
                  exit;
               end if;
            end loop;

            if Flag = 1 then

               Count := Count + 1;
               Primes (Count) := I;
            end if;

            if Count = N then
               Free (Primes);
               return I;
            end if;

            I := I + 2;

         end loop;

         return 1;
      end Nth_Prime;

   begin

      return Nth_Prime (n);

   end Prime;

   function IsPrime (N : Positive) return Boolean is
      Root, I : Integer;
   begin
      if N <= 1 then
         return False;
      end if;
      if N = 2 then
         return True;
      end if;
      if N mod 2 = 0 then
         return False;
      end if;

      I := 3;
      Root := Integer (Sqrt (Float (N)));
      while I <= Root loop
         if N mod I = 0 then
            return False;
         end if;
         I := I + 2;
      end loop;
      return True;

   end IsPrime;

end Primes;
