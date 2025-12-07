with Ada.Text_IO;      use Ada.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Primes;           use Primes;

procedure Program is
   Func_Name : String (1 .. 2);
   Number    : Positive;
begin

   if Argument_Count /= 2 then
      Put_Line ("Wrong number of arguments");
      return;

   end if;

   Func_Name := Argument (1);
   Number := Integer'Value (Argument (2));

   if Func_Name = "pn" then
      Put_Line
        ("Number of prime numbers less or equal to "
         & Integer'Image (Number)
         & ": "
         & Integer'Image (PrimeNumbers (Number)));
   end if;

   if Func_Name = "pr" then
      Put_Line
        (Integer'Image (Number)
         & "'th prime number: "
         & Integer'Image (Prime (Number)));
   end if;

   if Func_Name = "ip" then
      Put_Line (Boolean'Image (IsPrime (Number)));
   end if;

end Program;
