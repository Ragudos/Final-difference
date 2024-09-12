const { args } = require("./arguments");

function main() {
    console.log(args);

    const listSequences = [args.sequence];
    let commonDifference = 0;
    let currListIdx = 0;

    while (true) {
        const currList = listSequences[currListIdx];
        const differences = [];

        for (let i = 0; i < currList.length - 1; ++i) {
            const IS_END = i == currList.length - 1;

            if (IS_END) {
                differences.push(currList[i] - currList - 1);
            } else {
                differences.push(currList[i + 1] - currList[i]);
            }
        }

        if (differences.length < 2) {
            break;
        }

        let areAllDifferencesTheSame = true;

        for (let i = 0; i < differences.length; ++i) {
            for (let j = i + 1; j < differences.length; ++j) {
                if (differences[i] != differences[j]) {
                    areAllDifferencesTheSame = false;
                    break;
                }
            }

            if (!areAllDifferencesTheSame) {
                break;
            }
        }

        if (areAllDifferencesTheSame) {
            commonDifference = differences[0];

            break;
        }

        listSequences.push(differences);
        currListIdx += 1;
    }

    console.log(listSequences, commonDifference);
}

main();
