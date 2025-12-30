with Ada.Text_IO;                       use Ada.Text_IO;
with Ada.Integer_Text_IO;               use Ada.Integer_Text_IO;
with Ada.Long_Float_Text_IO;            use Ada.Long_Float_Text_IO;
with Ada.Numerics.Long_Elementary_Functions; use Ada.Numerics.Long_Elementary_Functions;

procedure Main is

   EPSILON : Long_Float := 0.1;

   type FuncType is access function (X : Long_Float) return Long_Float;

   procedure Write (F : FuncType; X : Long_Float) is
   begin
      Put (F (X));
      New_Line;
   end Write;

   function Square_1 (X : Long_Float) return Long_Float is
   begin
      return (X - 1.0) * (X + 2.0);
   end Square_1;

   function Test_Func (X : Long_Float) return Long_Float is
   begin
      return Cos (X / 2.0);
   end Test_Func;

   function Find_Zero (F : FuncType; Input_A : Long_Float; Input_B : Long_Float; Eps : Long_Float) return Long_Float is
      A   : Long_Float := Input_A;
      B   : Long_Float := Input_B;
      Mid : Long_Float;
   begin
      Mid := (A + B) / 2.0;

      if F (Mid) = 0.0 then
         return Mid;
      end if;

      while (B - A) / 2.0 > Eps loop
         if F (A) * F (Mid) < 0.0 then
            B := Mid;
         else
            A := Mid;
         end if;
         Mid := (A + B) / 2.0;
      end loop;

      return Mid;
   end Find_Zero;

   A, B      : Long_Float;
   Precision : Integer;
   Result    : Long_Float;

begin
   Put ("Enter a: ");
   Get (A);
   
   Put ("Enter b: ");
   Get (B);
   
   Put ("Choose precision: ");
   Get (Precision);

   for I in 1 .. Precision loop
      Result := Find_Zero (Test_Func'Access, A, B, EPSILON ** I);
      
      Put ("result: ");
      Put (Result, Aft => 20);
      New_Line;
   end loop;

end Main;