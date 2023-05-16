const css =`<style>
:root{--background-color:#EEEEEE;--text:#444444;--link-color:teal;}
@media(prefers-color-scheme:dark){
:root{--background-color:#222222;--text:#CCCCCC;--link-color:cadetblue;}}
body{background:var(--background-color);color:var(--text);}
body{margin:30px auto;max-width:700px;line-height:1.6;font-size:18px;font-family:Arial,Helvetica,sans-serif;color:var(--text);background:var(--background-color);padding:0 10px;}
h1{line-height:1.2;text-align:center;}
h2,h3{line-height:1.2;}
td,th{border:none!important;}
table{width:100%!important;}
a{color:var(--link-color);text-decoration:none;}
pre code{-webkit-overflow-scrolling: touch; display: block; overflow-x: scroll;}
</style>`;

const base = "https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json"; 
const self = "https://thesobersobber.github.io/CP-Snippets";
const gh = "https://github.com/theSoberSobber"; 
const ld = "https://www.linkedin.com/in/pavitchhabrawork";
const cf = "https://codeforces.com";
const raw = "https://raw.githubusercontent.com/theSoberSobber/CP-Snippets/main/snippets.json";


const {readFile, writeFile, open} = require("fs/promises"); 
const { marked } = require('marked');
const {genPdf} = require("./pdf-gen.js");

(async () => { 
    let file = await JSON.parse(await readFile('./snippets.json', 'utf8')); 
    let pre = {}; 
    let t=2; 
    for(let i in file){ 
        pre[i]=t; 
        t+=file[i].body.length+6; 
    }
    let index=`
# CP Snippets

| [About](${self}) | [Codeforces](${cf}) | [GitHub](${gh}) | [LinkedIn](${ld}) |
| - | - | - | - |

## About

A collection of CPP Snippets to aid in competetive programming. <br />
This site was auto generated with the help of [marked](https://www.npmjs.com/package/marked). <br />
The old version of site is available [here](${self}/old-index.html). <br />
This site is also available in the form of a PDF book for your convenience, you can download it from [here](https://github.com/theSoberSobber/CP-Snippets/blob/main/book/codebook-light.pdf).

---

`;
    let book=index;
    let links="", rest="";
    let newSite=`
## About

A collection of CPP Snippets to aid in competetive programming. <br />
This site was auto generated with the help of [marked](https://www.npmjs.com/package/marked). <br />
The old version of site is available [here](${self}/old-index.html). <br />
This site is also available in the form of a PDF book for your convenience, you can download it from [here](https://github.com/theSoberSobber/CP-Snippets/blob/main/book/codebook-light.pdf).
    
---
    
`;
    for(let i in file){ 
        links += `
- **[${i}](${self}/${file[i].prefix})** : ${file[i].description} `;
    }

    rest += `
\`\`\`bash
curl -L "${raw}" > snippets.json
\`\`\`
---
# Index - 

${links}`;
    index+=rest;
    newSite+=rest;
    const html = css+marked.parse(index);
    await writeFile('./docs/README.md', newSite);
    await writeFile('./docs/old-index.html', html);

    for(let topic in file){
        let code="";
        for(let line in file[topic].body){
            code+=file[topic].body[line];
            code+='\n';
        }
        code = code.substring(0, code.length-1);
        let oneFile = `
## ${topic}

- ${file[topic].description}
- \`\`\`
  ${self}/${file[topic].prefix}
  \`\`\`
- [github-snip-file](${base}#L${pre[topic]})

\`\`\`cpp
${code}
\`\`\`
`;  
        const fileHandler = await open(`./docs/${file[topic].prefix}.md`, 'w+');
        await writeFile(`./docs/${file[topic].prefix}.md`, oneFile);
        await fileHandler.close();
        book+=oneFile;
    }
    const bookHtml = css+marked.parse(book);
    await genPdf("./book/codebook-light.pdf", bookHtml, 0);
    await genPdf("./book/codebook-dark.pdf", bookHtml, 1);
})();