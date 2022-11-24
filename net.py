import networkx
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

G = networkx.Graph()

f = open('txt/mg')
for line in f:
  line = line.split('-')
  G.add_edge(int(line[0]), int(line[1]), weight=int(line[2]))

pos = networkx.spring_layout(G, k=100)
weight_labels = networkx.get_edge_attributes(G,'weight')
options = {
  "font_size": 20,
  "node_size": 1000,
  "node_color": "blue",
  "edge_color": "black",
  "linewidths": 2,
  "node_shape": 'o',
  "width": 1,
}
networkx.draw(G, pos, **options,with_labels=True)

networkx.draw_networkx_edge_labels(G,pos,edge_labels=weight_labels)
plt.savefig("pic/mg.png")
plt.show()
G.clear()
f.close()
  
f = open('txt/mst')
for line in f:
  line = line.split('-')
  G.add_edge(int(line[0]), int(line[1]), weight=int(line[2]))
  pos = networkx.spring_layout(G, k=100)
  weight_labels = networkx.get_edge_attributes(G,'weight')
  options = {
    "font_size": 20,
    "node_size": 1000,
    "node_color": "blue",
    "edge_color": "black",
    "linewidths": 2,
    "node_shape": 'o',
    "width": 1,
  }
  networkx.draw(G, pos, **options,with_labels=True)
  networkx.draw_networkx_edge_labels(G,pos,edge_labels=weight_labels)
  plt.savefig("pic/mst.png")
  plt.show(block=False)
  plt.pause(3)
  plt.close()
image = mpimg.imread("pic/mst.png")
plt.imshow(image)
G.clear()
f.close()