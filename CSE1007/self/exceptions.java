public class exceptions{
	public static void main(String[] args){
		int a,d;
		try{
			d = 0;
			a = 42/d;
			System.out.println("HI");
		}
		catch(ArithmeticException e){
			a=0;
			System.out.println(a);
		}
		finally{
		System.out.println("HI");
		}
	}
}
	 