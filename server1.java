import java.net.*;
import java.io.*;


public class server{
		public static void main(String []args)throws IOException{
		ServerSocket sock1=new ServerSocket(5942);
		while(true){
			Socket socketline=sock1.accept();
			BufferedReader loadbalancerpacket=new BufferedReader(new InputStreamReader(socketline.getInputStream()));
			String packet=loadbalancerpacket.readLine();
			System.out.println("Packet Retrieved From Client : "+packet);
		}
	}
}