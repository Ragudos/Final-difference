const { argv } = require("process");

const args = argv.slice(2).reduce((obj, curr) => {}, {});

module.exports = { args };
