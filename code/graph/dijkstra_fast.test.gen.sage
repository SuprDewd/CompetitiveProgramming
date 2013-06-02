gs = []

gs += [
       digraphs.RandomDirectedGNP(10, 0.2),
       digraphs.RandomDirectedGNP(300, 0.01),
       digraphs.RandomDirectedGNP(300, 0.2),
       digraphs.RandomDirectedGNP(300, 0.4),
       digraphs.RandomDirectedGNP(300, 0.6),
       digraphs.RandomDirectedGNP(300, 0.8),
       digraphs.RandomDirectedGNP(300, 0.9),
]

gs += list(digraphs(1))
gs += list(digraphs(2))
gs += list(digraphs(3))
gs += list(digraphs(4))

gs = [
        digraphs.Circuit(3),
        digraphs.Circuit(10),
        digraphs.Circulant(10, [2]),
        digraphs.Circulant(400, [2, 8, 19]),
        digraphs.Path(1),
        digraphs.Path(10),
        digraphs.Path(300),
        digraphs.RandomDirectedGN(10),
        digraphs.RandomDirectedGN(300),
        digraphs.RandomDirectedGNC(10),
        digraphs.RandomDirectedGNC(300),
        digraphs.Tournament(10),
        digraphs.Tournament(300),
]

print(len(gs))
for g in gs:
    print("%d %d" % (len(g.vertices()), len(g.edges())))
    for (u,v) in g.edge_iterator(labels=None):
        w = randint(0, 300)
        g.set_edge_label(u,v,w)
        print("%d %d %d" % (u, v, w))
    for u,d in sorted(g.shortest_path_all_pairs(by_weight=True)[0].items()):
        print ' '.join([ str(p) if p != Infinity else '-1' for v,p in sorted(d.items()) ])
