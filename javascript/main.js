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

        listSequences.push(differences);

        if (areAllDifferencesTheSame) {
            commonDifference = differences[0];

            break;
        }

        currListIdx += 1;
    }

    console.log("List of differences acquired");
    console.log("----------------------------");
    listSequences.forEach((list, i) => {
        const string = list.join(", ");

        console.log(string.padStart(Math.ceil(i * 2.5) + string.length, " "));
    });

    if (!commonDifference) {
        console.log("\nThere is no common difference");

        return;
    }

    let nextValueInSequence = 0;

    for (let i = 0; i < listSequences.length; ++i) {
        nextValueInSequence += listSequences[i][listSequences[i].length - 1];
    }

    console.log("\nNext value in sequence: ", nextValueInSequence);

    listSequences[0].push(nextValueInSequence);

    for (let i = 0; i < listSequences.length; ++i) {
        if (i < listSequences.length - 1) {
            listSequences[i + 1].push(
                listSequences[i].at(-1) - listSequences[i].at(-2),
            );
        }
    }

    console.log("Updated sequence list");
    console.log("----------------------------");
    listSequences.forEach((list, i) => {
        const string = list.join(", ");

        console.log(string.padStart(Math.ceil(i * 2.5) + string.length, " "));
    });
}

main();
