require "socket"

while true
server=TCPServer.open("192.168.36.128",4000)
loadbalancer=server.accept
puts loadbalancer.gets
loadbalancer.close
server.close
end