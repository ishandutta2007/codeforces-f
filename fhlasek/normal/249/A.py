l = raw_input().split()
y1, y2, yw, xb, yb, r = map(int, l)
y1 = 2 * (yw - r) - y1
y2 = 2 * (yw - r) - y2
y1 -= yb
y2 -= yb
yw -= yb
if((xb * (y1 - r) - xb * y2)**2 <= r**2 * (xb**2 + (y1 - r)**2)): print -1;
else: print "%.12lf" % ( xb * 1.0 * (y1 - yw) / (y1 - r))