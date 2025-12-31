package body Master_Mind is

   procedure GenerateRecursive (Index : Integer; CurrentSequence : in out Int_Array; FullList : in out List_Array; ListCount : in out Integer) is
   begin
      if Index = GUESSNUMBERS then
         FullList (ListCount) := CurrentSequence;
         ListCount := ListCount + 1;
         return;
      end if;

      for I in 1 .. GUESSRANGE loop
         CurrentSequence (Index) := I;
         GenerateRecursive (Index + 1, CurrentSequence, FullList, ListCount);
      end loop;
   end GenerateRecursive;

   function AllPosibilities return List_Array is
      Result : List_Array;
      CurrentSequence : Int_Array;
      ListCount : Integer := 0;
   begin
      GenerateRecursive (0, CurrentSequence, Result, ListCount);
      return Result;
   end AllPosibilities;

   procedure CalculateMatches (Secret : Int_Array; Guess : Int_Array; ResultOut : out Result_Array) is
      RightPlace : Integer := 0;
      WrongPlace : Integer := 0;
      SecretFreq : array (0 .. GUESSRANGE) of Integer := (others => 0);
      GuessFreq : array (0 .. GUESSRANGE) of Integer := (others => 0);
   begin
      for I in 0 .. GUESSNUMBERS - 1 loop
         if Secret (I) = Guess (I) then
            RightPlace := RightPlace + 1;
         else
            SecretFreq (Secret (I)) := SecretFreq (Secret (I)) + 1;
            GuessFreq (Guess (I)) := GuessFreq (Guess (I)) + 1;
         end if;
      end loop;

      for I in 1 .. GUESSRANGE loop
         WrongPlace := WrongPlace + Integer'Min (SecretFreq (I), GuessFreq (I));
      end loop;

      ResultOut (0) := RightPlace;
      ResultOut (1) := WrongPlace;
   end CalculateMatches;

   procedure FilterList (AllPermutations : List_Array; ValidMask : in out Mask_Array; CurrentGuess : Int_Array; UserRightPlace : Integer; UserWrongPlace : Integer) is
      TempResult : Result_Array;
      Candidate : Int_Array;
   begin
      for I in 0 .. TOTALPERMUTATIONS - 1 loop
         if ValidMask (I) then
            Candidate := AllPermutations (I);
            CalculateMatches (Candidate, CurrentGuess, TempResult);

            if TempResult (0) /= UserRightPlace or TempResult (1) /= UserWrongPlace then
               ValidMask (I) := False;
            end if;
         end if;
      end loop;
   end FilterList;

end Master_Mind;