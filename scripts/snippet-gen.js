// let snippet = {};
// snippet.name="test";
// snippet.prefix="test_prefix";
// snippet.description="test123";
// snippet.body=`#include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int solve(){
// 	int n; cin>>n;
// 	return 2*n;
// }

// int32_t main(){
// 	int t; cin>>t;
// 	while(t--) cout<<solve()<<'\\n';
// }`;

const formatSnippetBody = body => {
	const bodyArray = body.split('\n');
	return bodyArray.map((line, index) => {
			const formattedLine = line.replace(/"/g, '\\"');
			return `	${index !== 0 ? '\t\t' : ''}"${formattedLine}"${index !== bodyArray.length - 1 ? ',\n' : ''}`;
	}).join('');
};

const generateSnippet = (snippet) => {
	return `	"${snippet.name}": {
		"prefix":"${snippet.prefix}",
		"body": [
		${formatSnippetBody(snippet.body)}
		],
		"description":"${snippet.description}"
	}`;
};

// console.log(generateSnippet(snippet));

module.exports = {generateSnippet, formatSnippetBody};