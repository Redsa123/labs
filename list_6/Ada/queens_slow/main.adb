with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Main is
   N : Integer;
begin
   Put("Enter number of columns (N): ");
   Get(N);

   declare
      type Int_Array is array (0 .. N - 1) of Integer;
      
      CurrentPerm       : Int_Array;
      TotalPermutations : Long_Long_Integer;
      SolutionCount     : Integer := 0;

      function Factorial(K : Integer) return Long_Long_Integer is
         Result : Long_Long_Integer := 1;
      begin
         for I in 1 .. K loop
            Result := Result * Long_Long_Integer(I);
         end loop;
         return Result;
      end Factorial;

      procedure Swap(A: in out Integer; B: in out Integer) is
         Temp: Integer;
      begin
         Temp := A;
         A := B;
         B := Temp;
      end Swap;

      procedure Reverse_Arr(Arr : in out Int_Array; Start_Idx: Integer; Finish_Idx: Integer) is
         S: Integer := Start_Idx;
         F: Integer := Finish_Idx;
      begin
         while S < F loop
            Swap(Arr(S), Arr(F));
            S := S + 1;
            F := F - 1;
         end loop;
      end Reverse_Arr;

      procedure NextPermutation(Curr : in out Int_Array; Size : Integer) is
         I : Integer;
         J : Integer;
      begin
         I := Size - 2;
         
         -- Find the first element from the right that is smaller than its successor
         while I >= 0 and then Curr(I) >= Curr(I + 1) loop
            I := I - 1;
         end loop;

         if I >= 0 then
            J := Size - 1;
            -- Find the smallest element to the right of I that is greater than Curr(I)
            while Curr(J) <= Curr(I) loop
               J := J - 1;
            end loop;
            Swap(Curr(I), Curr(J));
         end if;
         
         Reverse_Arr(Curr, I + 1, Size - 1);
      end NextPermutation;

      function IsSafe(Next: Int_Array; Size: Integer) return Boolean is
         ColDiff : Integer;
         RowDiff : Integer;
      begin
         for I in 0 .. Size - 1 loop
            for J in I + 1 .. Size - 1 loop
               ColDiff := J - I;
               RowDiff := abs(Next(I) - Next(J));

               if RowDiff = ColDiff then
                  return False;
               end if;
            end loop;
         end loop;
         return True;
      end IsSafe;

   begin
      -- Initialize array: [1, 2, 3 ... N]
      for I in 0 .. N - 1 loop
         CurrentPerm(I) := I + 1;
      end loop;

      TotalPermutations := Factorial(N);

      for K in 1 .. TotalPermutations loop
         if IsSafe(CurrentPerm, N) then
            SolutionCount := SolutionCount + 1;
            Put("Solution ");
            Put(SolutionCount, Width => 0);
            Put(": ");
            
            -- FIX: Loop only goes to N - 1
            for J in 0 .. N - 1 loop 
               Put(CurrentPerm(J), Width => 0);
               Put(" ");
            end loop;
            New_Line;
         end if;
         NextPermutation(CurrentPerm, N);
      end loop;

      if SolutionCount = 0 then
         Put_Line("No solutions found.");
      else
         Put("Total solutions found: ");
         Put(SolutionCount, Width => 0);
         New_Line;
      end if;
   end;
end Main;