Exuberant Ctags 日本語対応版 x.xJ1
===============
                                                                2013年xx月xx日
                                                   東　浩仁 (HIGASHI Hirohito)
                                                              Twitter: @h_east
                                               https://github.com/vim-jp/ctags

はじめに
    Darren Hiebert (http://ctags.sourceforge.net/)氏が作成した Exuberant Ctags
    に日本語対応パッチをあてました。
    内部処理のみの対応です。ヘルプやメッセージの表示はオリジナルのままです。

パッチ内容
  ・文字列やコメント部分に日本語があってもparse処理が誤動作しないようにしまし
    た。

  ・以下のコマンドラインオプションを追加しました。
    --encoding=[エンコーディング]
        ソースファイルのエンコーディングを指定する。
        デフォルトは utf-8 です。
        ascii を指定した場合はオリジナルと同じ動作になります。

        ascii 以外を指定した場合は出力するタグファイルのヘッダにエンコー
        ド情報(_TAG_FILE_ENCODING)が付加されます。
            cp932を指定した場合
                !_TAG_FILE_ENCODING	cp932	//

  ※コンパイルオプション -DHAVE_ICONV
    を定義すると上記パッチが有効になります。
    定義しなければオリジナルと同じ動作になります。
    （配布時は定義された状態になっています）

  ※ regex(正規表現)の部分は日本語未対応です。
    --regex-* オプションのパラメータに日本語を含む正規表現が未サポートというこ
    とになります。

日本語対応版で追加されているファイル
    ctags_ja.html
        ctagsマニュアルの日本語訳HTMLファイルです。
        ●注意●旧バージョン(5.4J2)のものです。
    README_ja.txt
        このファイルです。
    mbcs.c
    mbcs.h
        マルチバイト処理のための定義/関数が記述されているCソース/ヘッダファイ
        ルです。

ctagsとは？
    ctagsは、テキストエディタやその他のユーティリティで (プログラミング言語で
    記述された)ソースファイル中のオブジェクト定義をすばやく簡単に検索するため
    のインデックス(タグ)を生成するためのツールです。 タグは、プログラミング言
    語で定義されるもののうちインデックスとして取得可能なオブジェクト(あるいは
    オブジェクト用に生成されたインデックスのエントリ) を示します。 

    機能を簡単に説明するとVisual C++等の統合開発環境で、とある関数呼び出し部分
    でマウス右クリックで「～ の定義位置を表示」を選ぶとその関数の定義場所へジャ
    ンプしますよね。このような動作を統合環境なしでおこなうものです。
    ctagsに対応しているエディタ(vi系, emacs系等)とctagsさえあればサクサクとソー
    スが読めます。

    *対応プログラム言語*
        Ant, Assembler, ASP, Awk, BASIC, BETA, C, C++, C#, COBOL, DOS Batch,
        Eiffel, Erlang, Flex, Fortran, HTML, Java, JavaScript, Lisp, Lua,
        Make, MATLAB, Objective Caml, Pascal, Perl, PHP, PL/SQL,
        Python (Pyrex/Cython), REXX, Ruby, Scheme,
        Shell scripts (Bourne/Korn/Z), S-Lang, SML (Standard ML), Tcl, TeX,
        Vera, Verilog, VHDL, Vim, YACC

使用許諾
    本プログラムはフリー・ソフトウェアです。
    GNU General Public License Ver.3 (GPLv3) に従って複製、頒布、変更すること
    ができます。Exuberant Ctags 日本語対応版を使用した事によるいかなる損害、不
    利益に対しても東はその責を負いません。

インストール方法（for Windows）
    ctags.exe をpathの通っているディレクトリにコピーしてください。
    （emacs系エディタを使用している人はファイル名を etags.exe に変更すると幸せ
    になれると思います）
    その他のファイルは実行時には必要ありません。

インストール方法（for UNIX/linux/MacOSX）
    $ ./configure
    $ make
    $ su
    Password:
    # make install

    ※ ./configure --disable-multibyte
      で日本語対応機能を無効にできます。

アンインストール方法（for Windows）
    レジストリ等は使用していません。
    ctags.exe を削除するだけです。

実行方法（for Windows）
    コマンドプロンプトで解析したいソースファイル群のあるディレクトリまで移動し、
        ctags -R
    を実行してください。vi上から実行する場合は
        :!ctags -R
    です。サブディレクトリ下のファイルも対象になります。
    同じ場所にtags (etags または ctags -e の場合は TAGS) というファイルが作成
    されます。対応エディタ(vi系, emacs系等)でソースファイルを開き、ジャンプし
    たい部分へカーソルを移動し、vi系ならノーマルモードで
        ctrl-]      (ctrlキーを押しながら ] )
    を入力してください。うまいこと定義位置へジャンプできたら成功です。
    戻るときは、
        ctrl-t      (ctrlキーを押しながら t )
    です。emacs系ならそれぞれ、
        M-.         (Metaキー押しながら . )
        M-*         (Metaキー押しながら * )
    かな。私はvim使いなのでemacsの事はよく分かりません;;

    「tagsファイルが見つからない」といった類のメッセージが出た場合は以下をチェッ
    クしてください。
    vi系
    ・tagsファイルがエディタのカレントディレクトリにあるか？
      (:pwd で表示されたディレクトリに tagsファイルがあるか)
    ・viの設定ファイル(.vimrc, _vimrc)でtagsオプションが変に設定されていない
か？
      (set tags=～ のパラメータにtagsがあるか)
      通常は、set tags=tags で問題ないと思います。

お薦めctags対応エディタ
    vim
        本家
            http://www.vim.org/
        KaoriYa版
            http://vim-jp.org/

謝辞
    このパッチを作成するにあたり土田健一さん作成のjvim (viクローンエディタ)
    のソースコードを参考および一部利用させていただきました。ソース利用を快諾し
    てくださった土田さんに感謝します。

    ctagsマニュアルの翻訳をしてくださった寺田隆平さん、ありがとうございます。

変更履歴
    ctags5.9I18N      (2014/xx/xx)
        ・iconvを使い日本語以外のエンコーディングに対応。

    ctags5.9J1      (2013/xx/xx)
        ・本家からforkしてvim-jp下で独自メンテナンス開始。

    ctags5.8J2      (2010/12/25)
        ・--jcodeオプションで sjis, euc, utf8 が指定された場合は出力するタグ
          ファイルのヘッダにエンコード情報(_TAG_FILE_ENCODING)を付加するように
          した。

    ctags5.8J1      (2009/07/10)
        ・5.8対応リリース
        ・UNIX/linux/MacOSX の --jcode のデフォルトを UTF-8 に変更。
        ・コマンドラインに日本語のフォルダ/ファイル名を指定された場合の動作不
          良を解消。

    ctags5.7J1      (2007/10/10)
        ・5.7対応リリース
        ・-x オプション指定時に日本語部分が文字化けする事があったのを修正。

    ctags5.6J1      (2006/06/12)
        ・5.6対応リリース

    ctags5.5.3J1     (2004/03/27)
        ・ctags -R で tags ファイルが作成されないバグがあったので Darren に報
          告して修正してもらいました。

    ctags5.5.3J1     (2004/03/22)
        ・5.5.3対応リリース

    ctags5.5.2J1     (2003/09/21)
        ・5.5.2対応リリース
        ・-f オプション等のパラメータを絶対パスで指定した場合、標準出力に
          'absolute of C:\～ = C:\～'
          と表示されるのを抑制 [Win32/DOS]
        ・ctags-*.tar.gz への ctags_j.html の収録忘れを解消

    ctags5.5.1J1     (2003/08/13)
        ・5.5.1対応リリース
        ・UNIX/linux/MacOSXへの配布形態をpatchリリースからフルソースリリース
          (ctags-*.tar.gz)に変更
          （./configure 後に Makefile の修正が必要なくなった）

    ctags5.5J1       (2003/04/03)
        ・5.5対応リリース(patch1 適用済み)

    ctags5.4J2       (2002/12/09)
        ・ascii(オリジナル動作)モードを追加
        ・utf-8に対応
          (--jcodeオプションのパラメータに ascii と utf8 を追加)

    ctags5.4J1       (2002/10/20)
        ・5.4対応リリース

    ctags5.3.1J1     (2002/09/13)
        ・5.3.1対応リリース
        ・日本語マニュアルctags_j.html追加

    ctags5.3J1       (2002/07/18)
        ・5.3対応リリース

    ctags5.2.3J2     (2002/05/18)
        ・EUCコードで半角カタカナが使用されていた場合正しくtagsが作成されない
          不具合を修正（一応SS3にも対応した）

    ctags5.2.3J1     (2002/03/05)
        ・5.2.3対応リリース

    ctags5.2.1J1     (2002/02/11)
        ・5.2.1対応リリース

    ctags5.2J1       (2001/12/24)
        ・5.2対応リリース

    ctags5.1J1       (2001/11/08)
        ・5.1対応リリース

    ctags5.0.1J1     (2001/05/01)
        ・5.0.1対応リリース
        ・日本語対応バージョン表記法を変更しました。 （J0.1 → J1）
        ・本ドキュメントとヘルプとtagsファイルに東のURL表示を追加しました。

    ctags5.0J0.1     (2001/03/27)
        ・5.0対応初回リリース
        ・-x オプション使用時に正しく日本語が処理されない不具合を修正

    ctags4.0.3J0.1   (2001/01/04)
        初回リリース

その他
    バグ、要望等ありましたらissueの発行をお願いします。
    https://github.com/vim-jp/ctags/issues

--
vi:textwidth=78 shiftwidth=4 expandtab:
