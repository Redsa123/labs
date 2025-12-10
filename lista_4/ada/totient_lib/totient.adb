with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

package body Totient is
   type Int_Array is array (Integer range <>) of Integer;

   procedure Dividers
     (N_In          : Integer;
      Dividers_List : in out Int_Array;
      Index         : in out Integer);

   function Totient (N : Integer) return Integer is
      Log_Val       : Float := Log (Float (N), 2.0);
      Dividers_List : Int_Array (0 .. Integer (Log_Val) + 1);
      Index         : Integer := 0;
      Result        : Integer := N;
   begin
      Dividers (N, Dividers_List, Index);

      for I in 0 .. Index - 1 loop
         Result := Result - Result / Dividers_List (I);
      end loop;

      return Result;

   end Totient;

   procedure Dividers
     (N_In : Integer; Dividers_List : in out Int_Array; Index : in out Integer)
   is
      N       : Integer := N_In;
      Sqrroot : Long_Long_Integer;
      I       : Long_Long_Integer := 3;

   begin

      if N mod 2 = 0 then
         while N mod 2 = 0 loop
            N := N / 2;
            if not (N mod 2 = 0) then
               Dividers_List (Index) := 2;
               Index := Index + 1;
            end if;
         end loop;
      end if;

      Sqrroot := Long_Long_Integer (Sqrt (Float (N)));

      while I <= Sqrroot loop
         if N mod Integer (I) = 0 then
            while N mod Integer (I) = 0 loop
               N := N / Integer (I);
               if not (N mod Integer (I) = 0) then
                  Dividers_List (Index) := Integer (I);
                  Index := Index + 1;
               end if;
            end loop;
         end if;
         I := I + 2;
      end loop;

      if N > 1 then
         Dividers_List (Index) := N;
         Index := Index + 1;
      end if;

   end Dividers;

end Totient;
