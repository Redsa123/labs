with Ada.Text_IO; use Ada.Text_IO;

package body list is

	function isEmpty (l : ListT) return Boolean is
	begin
		return l.first = null;
	end isEmpty;

	function Pop (l : in out ListT) return Integer is
		n : NodePtr := l.first;
		e : Integer;
	begin
		e := n.elem;
		l.first := n.next;
		if l.first = null then
			l.last := null;
		end if;
		l.length := l.length - 1;
		Free (n);
		return e;
	end Pop;

	procedure Push (l : in out ListT; e : Integer) is
		n : NodePtr := new Node;
	begin
		n.elem := e;
		n.next := l.first;
		l.first := n;
		if l.last = null then
			l.last := n;
		end if;
		l.length := l.length + 1;
	end Push;

	procedure Append (l : in out ListT; e : Integer) is
		n : NodePtr := new Node;
	begin
		n.elem := e;
		if l.first = null then
			l.first := n;
		else
			l.last.next := n;
		end if;
		l.last := n;
		l.length := l.length + 1;
	end Append;

	function Get (l : ListT; index : Integer) return Integer is
		n : NodePtr := l.first;
	begin
		for k in 1 .. index - 1 loop
			n := n.next;
		end loop;
		return n.elem;
	end Get;

	procedure Put (l : in out ListT; index : Integer; e : Integer) is
		n : NodePtr := l.first;
	begin
		for k in 1 .. index - 1 loop
			n := n.next;
		end loop;
		n.elem := e;
	end Put;

	procedure Insert (l : in out ListT; index : Integer; e : Integer) is
		n, new_node : NodePtr;
	begin
		if index = 1 then
			Push (l, e);
		elsif index = l.length + 1 then
			Append (l, e);
		else
			n := l.first;
			for k in 1 .. index - 2 loop
				n := n.next;
			end loop;
			new_node := new Node;
			new_node.elem := e;
			new_node.next := n.next;
			n.next := new_node;
			l.length := l.length + 1;
		end if;
	end Insert;

	procedure Delete (l : in out ListT; index : Integer) is
		n, temp : NodePtr;
	begin
		if index = 1 then
			declare
				ignore : Integer;
			begin
				ignore := Pop (l);
			end;
		else
			n := l.first;
			for k in 1 .. index - 2 loop
				n := n.next;
			end loop;

			temp := n.next;
			n.next := temp.next;

			if temp = l.last then
				l.last := n;
			end if;

			Free (temp);
			l.length := l.length - 1;
		end if;
	end Delete;

	procedure Print (l : ListT) is
		n : NodePtr := l.first;
	begin
		while n /= null loop
			Put (n.elem'Image);
			n := n.next;
		end loop;
		Put_Line (" (" & Length (l)'Image & " )");
	end Print;

	function Length (l : ListT) return Integer is
	begin
		return l.length;
	end Length;

	procedure Clean (l : in out ListT) is
		temp : Integer;
	begin
		while not isEmpty (l) loop
			temp := Pop (l);
		end loop;
	end Clean;

end list;
