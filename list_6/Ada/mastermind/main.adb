with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Master_Mind; use Master_Mind;

procedure Main is

   procedure PrintGuess (Guess : Int_Array) is
   begin
      Put ("[ ");
      for I in 0 .. GUESSNUMBERS - 1 loop
         Put (Guess (I), Width => 0);
         Put (" ");
      end loop;
      Put ("] ");
   end PrintGuess;

   AllPosibilitiesList : List_Array;
   ValidMask : Mask_Array := (others => True);
   Attempts : Integer := 1;
   RightPlace : Integer;
   WrongPlace : Integer;
   GuessIndex : Integer;
   CurrentGuess : Int_Array;
   Remaining : Integer;

begin
   AllPosibilitiesList := AllPosibilities;

   Put ("Think of a sequence of ");
   Put (GUESSNUMBERS, Width => 0);
   Put (" numbers (1-");
   Put (GUESSRANGE, Width => 0);
   Put_Line (").");
   Put_Line ("I will try to guess it.");
   Put_Line ("------------------------------------------------------------------");

   loop
      GuessIndex := -1;
      for I in 0 .. TOTALPERMUTATIONS - 1 loop
         if ValidMask (I) then
            GuessIndex := I;
            exit;
         end if;
      end loop;

      if GuessIndex = -1 then
         Put_Line ("Error: No valid possibilities left. You might have entered incorrect feedback previously.");
         exit;
      end if;

      CurrentGuess := AllPosibilitiesList (GuessIndex);

      Put ("Attempt ");
      Put (Attempts, Width => 0);
      Put (": I guess ");
      PrintGuess (CurrentGuess);
      New_Line;

      Put ("On right place: ");
      Get (RightPlace);
      Put ("On wrong place: ");
      Get (WrongPlace);

      if RightPlace = GUESSNUMBERS then
         Put ("I guessed it in ");
         Put (Attempts, Width => 0);
         Put_Line (" attempts!");
         exit;
      end if;

      FilterList (AllPosibilitiesList, ValidMask, CurrentGuess, RightPlace, WrongPlace);

      Remaining := 0;
      for I in 0 .. TOTALPERMUTATIONS - 1 loop
         if ValidMask (I) then
            Remaining := Remaining + 1;
         end if;
      end loop;

      Put ("Possible codes remaining: ");
      Put (Remaining, Width => 0);
      New_Line (2);

      Attempts := Attempts + 1;
   end loop;

end Main;