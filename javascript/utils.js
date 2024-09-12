function isNumber(n) {
    return (
        typeof n === "string" &&
        Number.isFinite(+n) &&
        n.trim() !== "" &&
        n - n === 0
    );
}

module.exports = { isNumber };
