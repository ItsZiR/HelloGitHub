import discord, random, json, datetime, asyncio
class MyClient(discord.Client):
    async def on_ready(self):
        print(f'{self.user} (ID: {self.user.id}) 準備追撞')
        print('------')
        statuses = ['野獸前輩','黑色的高級車','對為了保護後輩而擔下責任的三浦','提出和解條件','學狗叫，三回啊三回']
        while True:
            num = random.randint(0, len(statuses)-1)
            await client.change_presence(status=discord.Status.online, activity=discord.Game(name=statuses[num]))
            await asyncio.sleep(5)
    async def on_message(self, msg):
        if msg.author.bot:
            return
        if msg.content == '哈哈':
            await msg.channel.send('屁眼')
        #------------------------------------------------
        with open('data.json', 'r', encoding='utf-8') as data:
            inm = json.load(data)
        if msg.content == '~all':
            await msg.channel.send(f'目前資料數量 : {len(inm)}')
        #------------------------------------------------
        if msg.content == '~ref':
            source = discord.File('data.json')
            await client.get_channel(1042692091580526622).send(f'New version, volume : {len(inm)}', file=source)
            await msg.channel.send('已手動上傳資料')
        elif msg.content == '~refall':
            sources = [discord.File('TNOK.py'),discord.File('data.json')]
            await client.get_channel(1042692091580526622).send(f'New version, volume : {len(inm)}', files=sources)
            await msg.channel.send('已手動上傳最新版本')
        #------------------------------------------------
        elif '追撞' in msg.content or '追突' in msg.content or '高級車' in msg.content:
            if '三浦' in msg.content and '谷岡' in msg.content:
                for x in inm:
                        if msg.content == x['ctx']:
                            await msg.reply('重複的複製文', mention_author=False)
                            return
                with open('data.json', 'w', encoding='utf-8') as data:
                    inm.append(
                        {
                            "num" : "",
                            "ctx" : ""
                        }
                    )
                    inm[len(inm)-1]['num'] = len(inm)-1
                    inm[len(inm)-1]['ctx'] = msg.content
                    json.dump(inm, data, indent=2, ensure_ascii=False)
                    await msg.reply(f'已儲存新的複製文。目前數量 : {len(inm)}', mention_author=True)
            else:
                random.shuffle(inm)
                num = random.randint(0, len(inm)-1)
                TNOKEmbed = discord.Embed(title='黑色高級車複製文Ai',url='https://youtu.be/dQw4w9WgXcQ',description=inm[num]['ctx'], colour=discord.Color.default(),timestamp=datetime.datetime.now())
                TNOKEmbed.set_footer(text='下北沢')
                TNOKEmbed.color = discord.Color.blue()
                await msg.reply(embed=TNOKEmbed, mention_author=False)
        #------------------------------------------------
        elif '3' in msg.content or '三回' in msg.content:
            if ':' in msg.content: return
            await msg.reply('三回啊三回', mention_author=False)
            for i in range(3):
                random.shuffle(inm)
                num = random.randint(0, len(inm)-1)
                TNOKEmbed = discord.Embed(title='黑色高級車複製文Ai',url='https://youtu.be/dQw4w9WgXcQ',description=inm[num]['ctx'], colour=discord.Color.default(),timestamp=datetime.datetime.now())
                TNOKEmbed.set_footer(text='下北沢')
                TNOKEmbed.color = discord.Color.random()
                await msg.channel.send(embed=TNOKEmbed, mention_author=False)
        #------------------------------------------------    
client = MyClient(intents=discord.Intents.all())
client.run('MTA0MjMwNDMyNjcyODY4MzU0MA.G3esw1.2i1W4aMCILJqnelcOF1diKzgMvcsc-vCrnB4NA')