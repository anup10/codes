integer main() {
	integer a,b,c,d;
	a=Create("13.dat");
	a=Open("13.dat");
	d=1;
	b=130;
	while(b<1500) do
		c=Write(a,b);
		d=d+1;
		b=130*d;
	endwhile;
	c=Close(a);	
	return 0;
}
