integer main() {
	integer a,b,c,d;
	a=Create("12.dat");
	print(a);
	a=Open("12.dat");
	print("open");
	print(a);
	d=1;
	b=120;
	while(b<15000) do
		c=Write(a,b);
		print("12 ");
		print(c);
		d=d+1;
		b=120*d;
	endwhile;
	c=Close(a);	
	return 0;
}