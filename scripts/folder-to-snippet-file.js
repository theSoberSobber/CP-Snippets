const { writeFile } = require("fs/promises");
const { readdir, readFile } = require("fs/promises");
const { generateSnippet } = require("./snippet-gen.js");

(async () => { 
    const files = await readdir("./codes");
    let snipFile=`{
`;
    for( const file of files ){
        const contents = await readFile(`./codes/${file}`, 'utf8');
        const contentArray = contents.split('\n');
        const code = contents.substring(contentArray[0].length+contentArray[1].length+3)
        snipFile+=generateSnippet({
            name: file.substring(0, file.length-4),
            prefix: contentArray[0].substring(2),
            description: contentArray[1].substring(2),
            body: code
        });
        snipFile+=`,
`;
    }
    snipFile=snipFile.substring(0, snipFile.length-2);
    snipFile+=`
}`;
    writeFile("./snippets.json", snipFile);
})();