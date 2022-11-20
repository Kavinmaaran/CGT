import json
import networkx
import matplotlib.pyplot as plt

G = networkx.Graph()

f = open('mg')
for line in f:
  line = line.split('-')
  G.add_edge(int(line[0]), int(line[1]), weight=int(line[2]))

# for i,d in enumerate(data):
#     G.add_edge(data[i]["Vertex_1"], data[i]["Vertex_2"], weight=data[i]["Weight"])

pos = networkx.spring_layout(G, k=10)
weight_labels = networkx.get_edge_attributes(G,'weight')
networkx.draw(G, pos, font_color = 'pink', node_shape = 's',with_labels=True)

networkx.draw_networkx_edge_labels(G,pos,edge_labels=weight_labels)
plt.savefig("mg.png")
plt.show()
G.clear()
f.close()
  
f = open('mst')
for line in f:
  line = line.split('-')
  G.add_edge(int(line[0]), int(line[1]), weight=int(line[2]))

# for i,d in enumerate(data):
#     G.add_edge(data[i]["Vertex_1"], data[i]["Vertex_2"], weight=data[i]["Weight"])

pos = networkx.spring_layout(G, k=10)
weight_labels = networkx.get_edge_attributes(G,'weight')
networkx.draw(G, pos, font_color = 'pink', node_shape = 's',with_labels=True)

networkx.draw_networkx_edge_labels(G,pos,edge_labels=weight_labels)
plt.savefig("mst.png")
plt.show()
G.clear()
f.close()