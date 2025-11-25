with Ada.Text_IO;                    use Ada.Text_IO;
with Ada.Integer_Text_IO;          use Ada.Integer_Text_IO;
with Ada.Long_Long_Integer_Text_IO; use Ada.Long_Long_Integer_Text_IO;
with Ada.Unchecked_Deallocation;

procedure Main is
   type Pascal_Array is array (Integer range <>) of Long_Long_Integer;

   type Pascal_Row_Access is access Pascal_Array;

   procedure Free is
        new Ada.Unchecked_Deallocation(Pascal_Array, Pascal_Row_Access);

   function CalcNewton (N : Integer; K : Integer) return Long_Long_Integer is
      K_Optimized : Integer := K;
      Tab : Pascal_Row_Access;
      Result : Long_Long_Integer;
      J_Max : Integer;
   begin
      if K < 0 or K > N then
         return 0;
      end if;

      if K_Optimized > N / 2 then
         K_Optimized := N - K_Optimized;
      end if;

      if K_Optimized = 0 then
         return 1;
      end if;

      Tab := new Pascal_Array'(0 .. K_Optimized => 0);
      Tab(0) := 1;


      for I in 1 .. N loop
         J_Max := Integer'Min (I, K_Optimized);
            for J in reverse 1 .. J_Max loop
               Tab.all (J) := Tab.all (J) + Tab.all (J - 1);
            end loop;
      end loop;

      Result := Tab.all (K_Optimized);

      Free (Tab);

      return Result;
   end CalcNewton;

   N, K : Integer;
   Result : Long_Long_Integer;
begin
   Put ("Enter n: ");
   Get (N);

   Put ("Enter k: ");
   Get (K);

   Result := CalcNewton (N, K);

   Put ("Result: ");
   Put (Item => Result);
   New_Line;

end Main;