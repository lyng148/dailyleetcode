var getLastMoment = function(n, left, right) {
    return Math.max(
        left.length ? _.max(left) : 0,
        right.length ? n - _.min(right) : 0,
    );
};