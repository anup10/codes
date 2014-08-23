integer main() {
	integer n;
	string a;
	print("Enter name:");
	read(a);
	print("Enterno:");
	read(n);
	
	integer b,c,d,e,f;
	b=Create(a);
	c=Open(a);
	
	d=n;
	f=1;
	
	while(d<50000) do
		e=Write(c,d);
		f=f+1;
		d=n*f;
	endwhile;
	
	d=Close(c);
	return(0);
}
