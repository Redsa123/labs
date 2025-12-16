with Ada.Text_IO;                   use Ada.Text_IO;
with Ada.Integer_Text_IO;           use Ada.Integer_Text_IO;
with Ada.Strings.Unbounded;         use Ada.Strings.Unbounded;
with Ada.Strings.Unbounded.Text_IO; use Ada.Strings.Unbounded.Text_IO;

with list; use list;

procedure Main is
	l        : ListT;
	r        : Integer;
	idx      : Integer;
	command  : Unbounded_String;
	continue : Boolean := True;
	len      : Integer;
begin
	Put_Line ("--- Created a new list ---");
	Put_Line
	  ("Available commands: pop, push, print, append, get, put, insert, delete, clean, exit");
	while continue loop
		Put ("Command: ");
		Get_Line (command);

		if command = "Pop" then
			if not isEmpty (l) then
				r := Pop (l);
				Put_Line ("Result: " & r'Image);
			else
				Put_Line ("Error - stack is empty!");
			end if;

		elsif command = "Push" then
			Put ("Value: ");
			Get (r);
			Skip_Line;
			Push (l, r);
			Put_Line ("Result: OK");

		elsif command = "Append" then
			Put ("Value: ");
			Get (r);
			Skip_Line;
			Append (l, r);
			Put_Line ("Result: OK");

		elsif command = "Insert" then
			Put ("Index: ");
			Get (idx);
			Put_Line ("");
			Put ("Value: ");
			Get (r);
			Put_Line ("");

			len := Length (l);
			if idx >= 1 and idx <= len + 1 then
				Insert (l, idx, r);
				Put_Line ("Result: OK");
			else
				Put_Line ("Error - bad index!");
			end if;

		elsif command = "Delete" then
			Put ("Index: ");
			Get (idx);
			Skip_Line;

			len := Length (l);
			if idx >= 1 and idx <= len then
				Delete (l, idx);
				Put_Line ("Result: OK");
			else
				Put_Line ("Error - bad index!");
			end if;

		elsif command = "Get" then
			Put ("Index: ");
			Get (idx);
			Skip_Line;

			len := Length (l);
			if idx >= 1 and idx <= len then
				r := Get (l, idx);
				Put_Line ("Result: " & r'Image);
			else
				Put_Line ("Error - bad index!");
			end if;

		elsif command = "Put" then
			Put ("Index: ");
			Get (idx);
			Skip_Line;
			Put ("Value: ");
			Get (r);
			Skip_Line;

			len := Length (l);
			if idx >= 1 and idx <= len then
				list.Put (l, idx, r);
				Put_Line ("Result: OK");
			else
				Put_Line ("Error - bad index!");
			end if;

		elsif command = "Print" then
			Put ("Result: ");
			Print (l);

		elsif command = "Length" then
			r := Length (l);
			Put_Line ("Result: " & r'Image);

		elsif command = "Clean" then
			Clean (l);
			Put_Line ("Result: OK");

		elsif command = "Exit" then
			continue := False;
		else
			Put_Line ("Unavailable command yet");
		end if;
	end loop;

	Clean (l);
end Main;
