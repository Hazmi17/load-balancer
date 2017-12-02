import java.net.*;
import java.io.*;

public class loadBalancer{
		public static void main(String []args)throws IOException{
		ServerSocket sock1=new ServerSocket(1221);
		while(true){
			Socket socketline=sock1.accept();
			BufferedReader clientmessage=new BufferedReader(new InputStreamReader(socketline.getInputStream()));
			String clientpacket=clientmessage.readLine();

			if(clientpacket.contains("Mail")){
			Socket sv1=new Socket("192.168.232.128",5942);
			DataOutputStream packettoserver1=new DataOutputStream(sv1.getOutputStream());
			packettoserver1.writeBytes(clientpacket+"\n");
			sv1.close();
			}

			else if(clientpacket.contains("Admin")){
			Socket sv2=new Socket("192.168.232.129",6788);
			DataOutputStream packettoserver2=new DataOutputStream(sv2.getOutputStream());
			packettoserver2.writeBytes(clientpacket+"\n");
			sv2.close();
			}

			else{System.out.println("Packet Lost!");}
			}
		}
}
