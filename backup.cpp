for (auto u : list_of_LinkedList) {
cout<<indexMain<<endl;
if (holds_alternative<list<int>>(u)) {

//We can delete this for deleting the list
//            QString qstr = QString::fromStdString("Int List "+to_string(indexMain));
//            QTreeWidgetItem *root = new QTreeWidgetItem( ui->treeWidget, QStringList()<<qstr<<"Data");
int leafIndex =1;

for (auto i : get<list<int>>(u)) {
//                QString lQstr = QString::fromStdString("Node "+ to_string(leafIndex));
//                QTreeWidgetItem *leaf = new QTreeWidgetItem( root, QStringList()<<lQstr<<QString::number(i));
leafIndex++;
}

}

else if (holds_alternative<list<string>>(u)) {
//            QString qstr = QString::fromStdString("String List "+to_string(indexMain));
//            QTreeWidgetItem *root = new QTreeWidgetItem( ui->treeWidget, QStringList()<<qstr<<"Data");
int leafIndex =1;

for (auto s : get<list<string>>(u)) {
//                QString lQstr = QString::fromStdString("Node "+ to_string(leafIndex));
//                QTreeWidgetItem *leaf = new QTreeWidgetItem( root, QStringList()<<lQstr<<QString::fromStdString(s));

leafIndex++;
}
}
indexMain++;
}

//    QStringList list;
//
//    list << "alpha" << "beta" << "gamma"<<QString::number(100) ;
//
//    QStringListIterator it(list);
//    while (it.hasNext())
//    {
//        QListWidgetItem *listItem = new QListWidgetItem(it.next(),ui->listWidget);
//        listItem->setCheckState(Qt::Unchecked);
//        ui->listWidget->addItem(listItem);
//    }