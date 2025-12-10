with Ada.Text_IO; use Ada.Text_IO;
with Ada.Command_Line;
with Ada.Strings.Fixed;
with Totient;

procedure Main is
   Argc : Integer := Ada.Command_Line.Argument_Count + 1;
begin
   if Argc < 2 then
      New_Line;
      Put_Line ("Wrong number of arguments.");
      Put ("Usage: /program <number>");
   end if;
   New_Line;

   for I in 1 .. Ada.Command_Line.Argument_Count loop
      declare
         Arg : String := Ada.Command_Line.Argument (I);
         Val : Integer := Integer'Value (Arg);
         Result : Integer := Totient.Totient (Val);
         Result_Str : String := Integer'Image (Result);
      begin
         Put ("totient(" & Arg & ") = " & Ada.Strings.Fixed.Trim(Result_Str, Ada.Strings.Left) & ";");
         New_Line;
      end;
   end loop;
   New_Line;
end Main;