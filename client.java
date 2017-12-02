import java.io.*;
import java.net.*;

public class client{
		public static void main(String []args)throws IOException{
			Socket clientsocket=new Socket("192.168.116.129",1221);
			DataOutputStream toloadbalancer=new DataOutputStream(clientsocket.getOutputStream());
			BufferedReader userpacket=new BufferedReader(new InputStream(System.in));
			String packmessage=userpacket.readLine();
			toloadbalancer.writeBytes(packmessage);
			clientsocket.close();
		}
}