with Ada.Text_IO; use Ada.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;

procedure Main is
    package Int_IO is new Ada.Text_IO.Integer_IO(Integer); use Int_IO;
    package Long_IO is new Ada.Text_IO.Integer_IO(Long_Long_Integer); use Long_IO;

    N : Integer;
    Solutions : Long_Long_Integer := 0;

    procedure Queens is
        type Int_Array is array (0 .. N - 1) of Integer;
        type Bool_Array is array (0 .. N - 1) of Boolean;
        type Bool_Array_Diag is array (0 .. 2 * N - 1) of Boolean;

        Position : Int_Array := (others => 0);
        Raw : Bool_Array := (others => False);
        Diagonal1 : Bool_Array_Diag := (others => False);
        Diagonal2 : Bool_Array_Diag := (others => False);

        procedure PrintResult is
        begin
            Solutions := Solutions + 1;

            for I in 0 .. N - 1 loop
                Put(Position(I) + 1, Width => 0);
                Put(" ");
            end loop;
            New_Line;
        end PrintResult;

        procedure Set(I : Integer) is
            Diagonal1_Idx : Integer;
            Diagonal2_Idx : Integer;
        begin
            if I = N then
                PrintResult;
                return;
            end if;

            for J in 0 .. N - 1 loop
                Diagonal1_Idx := I + J;
                Diagonal2_Idx := I - J + (N - 1);

                if not (Raw(J) or Diagonal1(Diagonal1_Idx) or Diagonal2(Diagonal2_Idx)) then
                    Position(I) := J;
                    Raw(J) := True;
                    Diagonal1(Diagonal1_Idx) := True;
                    Diagonal2(Diagonal2_Idx) := True;

                    Set(I + 1);

                    Raw(J) := False;
                    Diagonal1(Diagonal1_Idx) := False;
                    Diagonal2(Diagonal2_Idx) := False;
                end if;
            end loop;
        end Set;

    begin
        Set(0);
    end Queens;

begin
    if Argument_Count /= 1 then
        Put_Line("Wrong number of arguments");
        Set_Exit_Status(Failure);
        return;
    end if;

    begin
        N := Integer'Value(Argument(1));
    exception
        when others =>
            N := 0;
    end;

    if N <= 0 then
        Put_Line("n has to be greater than 0");
        Set_Exit_Status(Failure);
        return;
    end if;

    Queens;

    Put("Total number of solutions: ");
    Put(Solutions, Width => 0);
    New_Line;
end Main;