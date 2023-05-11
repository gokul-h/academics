import java.io.*;

public class editor
{

  public static void main (String[]args) throws IOException
  {
    BufferedReader br =
      new BufferedReader (new InputStreamReader (System.in, System.console().charset() ));
      System.out.println ("Enter your File\n");
      System.out.println ("Type stop to exit\n");
      String[] str = new String[100];
    for (int i = 0; i < 100; i++)
      {
	str[i] = br.readLine ();
	if (str[i].equals ("stop"))
	  break;
      }
    System.out.println ("Here is your File\n");
    for(int i=0;i<100;i++){
		if (str[i].equals ("stop"))
		break;
        System.out.println(str[i]);
    }
  }
}
