// Use this script to sync the codes folder when you edit the snippets.json directly for some reason

const {readFile, writeFile, open} = require("fs/promises");

(async () => { 
    let file = await JSON.parse(await readFile('./snippets.json', 'utf8')); 
    for(let topic in file){
        let code=`//${file[topic].prefix}
//${file[topic].description}

`;
        for(let line in file[topic].body){
            code+=file[topic].body[line];
            code+='\n';
        }
        code = code.substring(0, code.length-1);

        await open(`./codes/${file[topic].prefix}.cpp`, 'w+');
        await writeFile(`./codes/${file[topic].prefix}.cpp`, code);
    }
})();