pair<ld, ld> intersect(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2){
	ld det = a1 * b2 - a2 * b1;
	if(!det) return mp(1e18, 1e18);
	else{
		ld x = (b2 * c1 - b1 * c2) / det;
		ld y = (a1 * c2 - a2 * c1) / det;
		return mp(x, y);
	}
}
