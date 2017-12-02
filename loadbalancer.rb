require "socket"

loadbalancer=TCPServer.open("192.168.38.129",2000)

while true
client.loadbalancer.accept
rhost=client.peeraddr.accept
puts "#{rhost} connect to loadbalancer"
fromclient=client.gets
puts"Packet from client: #{fromclient}"

if fromclient=="boy"
sockettos1==TCPSocket.open("192.168.36.128",3000)
sockettos1.write(fromclient)
sockettos1.close

elsif fromclient=="Girl"
sockettos2.TCPSocket.open("192.168.36.129",4000)
sockettos2.write(fromclient)
sockettos2.close

else
puts "Error!"

end
end