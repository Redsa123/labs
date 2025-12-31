package Master_Mind is

   GUESSRANGE : constant Integer := 6;
   GUESSNUMBERS : constant Integer := 4;
   TOTALPERMUTATIONS : constant Integer := GUESSRANGE ** GUESSNUMBERS;

   type Int_Array is array (0 .. GUESSNUMBERS - 1) of Integer;
   type List_Array is array (0 .. TOTALPERMUTATIONS - 1) of Int_Array;
   type Mask_Array is array (0 .. TOTALPERMUTATIONS - 1) of Boolean;
   type Result_Array is array (0 .. 1) of Integer;

   function AllPosibilities return List_Array;

   procedure CalculateMatches (Secret : Int_Array; Guess : Int_Array; ResultOut : out Result_Array);

   procedure FilterList (AllPermutations : List_Array; ValidMask : in out Mask_Array; CurrentGuess : Int_Array; UserRightPlace : Integer; UserWrongPlace : Integer);

end Master_Mind;